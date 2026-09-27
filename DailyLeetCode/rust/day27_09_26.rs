impl Solution {
    pub fn reverse_parentheses(s: String) -> String {
        // Ciag bajtów u8 jako widok czy slice co patrzy na kade ciagle pamieciowo elementy czyli typ to &[u8]
        let bytes = s.as_bytes();
        let n = bytes.len();

        // vector pokazujacy dla kazdego nawaiasa gdzie jest jego nawias dla rezty poakzuje 0
        let mut pair = vec![0usize; n];
        //usize to jest zalezny od sysemu uint tutaj chyba 8 bajtow
        let mut stack: Vec<usize> = Vec::new();

        for i in 0..n {
            match bytes[i] {
                b'(' => stack.push(i),
                b')' => {
                    let j = stack.pop().unwrap(); // ryzyka wywalenia na unwrap jak bylby pusty
                                                  // bo pop() zwraca Option<usize>:Some(x) alb Option<usize>:None
                    pair[i] = j;
                    pair[j] = i;
                }
                _ => {}
            }
        }

        // Przejdź po stringu, "teleportując się" na nawiasach
        let mut res = String::with_capacity(n);
        let mut i = 0usize;
        let mut forward = true;
        while i < n {
            let c = bytes[i];
            if c == b'(' || c == b')' {
                i = pair[i];
                forward = !forward;
            } else {
                res.push(c as char);
            }
            if forward {
                i += 1
            } else {
                i -= 1
            }
        }
        res
    }
}
