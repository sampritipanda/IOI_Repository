unit graderlib;

interface
    procedure playRound(var B, R: array of longint);

implementation
    uses koala;

    const
        MAX_N = 105;
        MAX_W = 205;
    var
        N, W : longint;
        P : array[0..MAX_N] of longint;
        maxQueries : longint = 3200;
        numQueries : longint;

    procedure playRound(var B, R: array of longint);
    var
        i, j, S, v, ii, o, h, hn, cur : longint;
        cache, num : array[0..1, 0..MAX_W] of longint;
        taken: array[0..MAX_N, 0..MAX_W] of boolean;
    begin
        S := 0;
        for i := 0 to N - 1 do
        begin
            if not ((B[i] >= 0) and (B[i] <= W)) then
            begin
                Writeln('Invalid query.');
                halt(0);
            end;
            S += B[i];
        end;
        if S > W then
        begin
            Writeln('Invalid query.');
            halt(0);
        end;

        Inc(numQueries);
        if numQueries > maxQueries then
        begin
            Writeln('Too many queries.\n');
            halt(0);
        end;

        for i := 0 to MAX_W do
        begin
            cache[1, i] := 0;
            num[1, i] := 0;
        end;

        for i := 0 to N - 1 do
        begin
            v := B[i] + 1;
            ii := i and 1;
            o := ii xor 1;
            for j := 0 to W do
            begin
                cache[ii,j] := cache[o,j];
                num[ii,j] := num[o,j];
                taken[i,j] := false;
            end;
            for j := W downto v do
            begin
                h := cache[o,j-v] + P[i];
                hn := num[o,j-v] + 1;
                if (h > cache[ii,j]) or ((h = cache[ii,j]) and (hn > num[ii,j])) then
                    begin
                        cache[ii,j] := h;
                        num[ii,j] := hn;
                        taken[i,j] := true;
                    end
                else
                    taken[i,j] := false;
            end;
        end;

        cur := W;
        for i := N - 1 downto 0 do
        begin
            if taken[i,cur] then
                R[i] := B[i] + 1
            else
                R[i] := 0;
            cur -= R[i];
        end;
    end;

    procedure runGame(F : longint);
    var
        i : longint;
        userP : array[0..MAX_N] of longint;
    begin
        Read(N, W);
        for i := 0 to N - 1 do Read(P[i]);

        numQueries := 0;
        if F = 1 then
            Writeln(minValue(N, W))
        else if F = 2 then
            Writeln(maxValue(N, W))
        else if F = 3 then
            Writeln(greaterValue(N, W))
        else if F = 4 then
        begin
            allValues(N, W, userP);
            for i := 0 to N-1 do
                Write(userP[i], ' ');
            Writeln('');
        end;
        Writeln('Made ', numQueries, ' calls to playRound.');
    end;

    procedure grader();
    var
        i, F, G : longint;
    begin
        Read(F, G);
        for i := 0 to G - 1 do runGame(F);
    end;

begin
    grader();
end.
