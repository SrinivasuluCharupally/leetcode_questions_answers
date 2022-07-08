// https://tenderleo.gitbooks.io/leetcode-solutions-/content/GoogleEasy/157.html
// * @param buf Destination buffer
//     * @param n   Maximum number of characters to read
//     * @return    The number of characters read

//

int read(char[] buf, int n) {
        int index =0;
        char[] r4 = new char[4];
        while(index < n){
            int c = read4(r4);
            for(int i=0; i<c && index < n; i++){
                buf[index++] = r4[i];
            }
            if(c < 4) break;
        }

        return index;
    }

