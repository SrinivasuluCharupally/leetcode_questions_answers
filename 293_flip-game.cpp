// details : https://leetcode.ca/all/293.htm
// // You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

// Write a function to compute all possible states of the string after one valid move.

// For example, given s = "++++", after one move, it may become one of the following states:

// [
//   "--++",
//   "+--+",
//   "++--"
// ]
// If there is no valid move, return an empty list [].


public List<String> generatePossibleNextMoves(String s) {
    List<String> res = new ArrayList<String>();
    if(s == null || s.length() == 0) return res;
    int start = 0;
    char[] charArr = s.toCharArray();
    while(start < s.length() - 1){
        if(isConsecutiveSame(charArr, start)){
            flip(charArr, start);
            res.add(new String(charArr));
            flip(charArr, start);
        }
        start++;
    }
    return res;
}

private boolean isConsecutiveSame(char[] charArr, int i){
    return charArr[i] == charArr[i + 1] && charArr[i] == '+';
}

private void flip(char[] charArr, int i){
    if(charArr[i] == '+'){
        charArr[i] = '-';
        charArr[i + 1] = '-';
    } else {
        charArr[i] = '+';
        charArr[i + 1] = '+';
    }
}

