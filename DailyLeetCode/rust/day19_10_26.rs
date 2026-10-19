impl Solution {
    pub fn target_indices(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut x = 0;
        let mut tar_n = 0;

        for &num in &nums {
            match num.cmp(&target) {
                std::cmp::Ordering::Less => x += 1,
                std::cmp::Ordering::Equal => tar_n += 1,
                _ => (),
            }
        }

        (x..x + tar_n).collect()
    }
}
