unit koala;

interface
    function minValue(N, W: longint) : longint;
    function maxValue(N, W: longint) : longint;
    function greaterValue(N, W : longint) : longint;
    procedure allValues(N, W : longint; var P : array of longint);

implementation
    uses graderlib;

    function minValue(N, W: longint) : longint;
    begin
        { TODO: Implement Subtask 1 solution here. }
        { You may leave this function unmodified if you are not attempting this
        subtask. }
        minValue := 0;
    end;

    function maxValue(N, W: longint) : longint;
    begin
        { TODO: Implement Subtask 2 solution here. }
        { You may leave this function unmodified if you are not attempting this
        subtask. }
        maxValue := 0;
    end;

    function greaterValue(N, W : longint) : longint;
    begin
        { TODO: Implement Subtask 3 solution here. }
        { You may leave this function unmodified if you are not attempting this
        subtask. }
        greaterValue := 0;
    end;

    procedure allValues(N, W : longint; var P : array of longint);
    begin
        if W = 2*N then
            begin
                { TODO: Implement Subtask 4 solution here. }
                { You may leave this block unmodified if you are not attempting
                this subtask. }
            end
        else
            begin
                { TODO: Implement Subtask 5 solution here. }
                { You may leave this block unmodified if you are not attempting
                this subtask. }
            end;
    end;

end.
