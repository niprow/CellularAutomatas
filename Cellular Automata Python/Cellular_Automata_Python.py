
bools_length = 200;
bools = [False] * bools_length;

def get_next_bool(position) :
    #check position length
    if(position > bools_length) :
        print("you fucked up")
        return False;

    #get booleans
    left = False;
    if (position == 0) :
        left = False;
    else :
        left = bools[position - 1];
    mid = bools[position];
    right = True;
    if (position == bools_length - 1) :
        right = bools[0];
    else :
        right = True;
    
    #return the right boolean
    if (left and mid and right) : return True;
    if (left and not mid and right) : return False;
    if (left and mid and not right) : return True;
    if (left and not mid and not right) : return False;
    if (not left and mid and right) : return False;
    if (not left and not mid and right) : return True;
    if (not left and mid and not right) : return True;
    if (not left and not mid and not right) : return False;

def change_bools() :
    new_bools = [True] * bools_length;
    for i in range(bools_length) :
        new_bools[i] = get_next_bool(i)
    for i in range(bools_length) :
        bools[i] = new_bools[i];

def draw() :
    for i in bools :
        if (i) : print("0", end = "");
        else : print(" ", end = "");
    print("")
#               --------------------- start ---------------------

#init bools
bools[2] = True;
bools[3] = True;
bools[4] = True;
bools[20] = True;
bools[22] = True;
bools[36] = True;

for i in range(100) :
    draw();
    change_bools();