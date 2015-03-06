# Jigsaw Puzzle Solving

class Grid
  def initialize(height, width)
    @height, @width = height, width
    @box = Array.new(height + 1) { [0] * (width + 1) }
    @number_of_pieces = 0
    @next_empty_x = @next_empty_y = 1
    @free_cells = width * height
  end

  def score
    @free_cells/(width * height).to_f
  end

  def fit(piece)
    return if (piece.height + @next_empty_x - 1) > @height
    if (piece.width + @next_empty_y - 1) <= @width
      (1..piece.height).each do |i|
        (1..piece.width).each do |j|
          next unless piece.bounding_box[i][j]
          @box[@next_empty_x + i - 1][@next_empty_y + j - 1] = piece.id
        end
      end
    else
      @next_empty_x += 1
      @next_empty_y = 1
      return fit(grid, piece)
    end
  end

  def to_s
    @box[1..-1].map { |a| a[1..-1].join(' ') }.join("\n")
  end
end

class Piece
  attr_reader :bounding_box, :id

  def initialize(cells, id)
    @id = id
    @cells = cells.sort
    @bounding_box = Array.new(height + 1) { [0] * (width + 1) }
    @cells.each { |x, y| @bounding_box[x][y] = 1 }
  end

  def to_s
    @bounding_box[1..-1].map { |a| a[1..-1].join(' ') }.join("\n")
  end

  def rectangle?
    !@bounding_box.flatten.include? 0
  end

  def width
    @width ||= @cells.max { |a, b| a[1] <=> b[1] }[1]
  end

  def height
    @height ||= @cells.last.first
  end
end

def solve(grid, pieces)
  pieces.each { |piece| grid.fit(piece) if piece.rectangle? }
  pieces.each { |piece| grid.fit(piece) unless piece.rectangle? }
  grid
end

def main
  h, w, k = gets.split.map(&:to_i)
  grid = Grid.new(h, w)
  pieces = []
  k.times do |i|
    p = gets.to_i
    pieces << (Piece.new p.times.map { gets.split.map(&:to_i) }, i + 1)
  end

  puts solve grid, pieces
end

main()
