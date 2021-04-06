#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
	TreeNode(int val, TreeNode * left, TreeNode * right) : val(val), left(left), right(right) {}
};

class Solutions {
	int matrixScore(std::vector<std::vector<int>>& A){
		int rows = A.size();
		int cols = A[0].size();
		int ans = 0;
		for(int i = 0; i < cols; ++i){
			int zeros = 0;
			for(int j = 0; j < rows; ++j){
				zeros += (A[j][i] ^ A[j][0]);
			}
			ans += (std::max(zeros, rows - zeros) * (1 << (cols - i - 1)));
		}
		return ans;
	}

	bool hasDuplicateNumber {
		std::unordered_set<int> temp;
		for(int num : nums) {
			if(temp.find(num) != temp.end()){
				return true;
			} else {
				temp.insert(num);
			}
		}
		return false;
	}

	//Greedy algorithm.
	int maxProfit(std::vector<int>& prices, int fee) {
		int buy = prices[0] + fee;
		int profit = 0;
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] + fee < buy) {
				buy = prices[i] + fee;
			}
			if (prices[i] > buy) {
				profit += prices[i] - buy;
				buy = prices[i];
			}
		}
		return profit;
	}

	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hashtable;
		for (int i = 0; i < nums.size(); ++i) {
			auto it = hashtable.find(target - nums[i]);
			if (it != hashtable.end()) {
				return {it->second, i};
			} else {
				hashtable[nums[i]] = i;
			}
		}
		return {};
	}

	ListNode * addTwoNumbers(ListNode * l1, ListNode * l2) {
		ListNode * head = nullptr, * tail = nullptr;
		int carry = 0;
		while (l1 || l2) {
			int left = l1 ? l1->val : 0;
			int right = l2 ? l2->val : 0;
			int sum = left + right + carry;
			if (!head) {
				head = tail = new ListNode(sum % 10);
			} else {
				tail->next = new ListNode(sum % 10);
				tail = tail->next;
			}
			carry = sum / 10;
			if (l1) {
				l1 = l1->next;
			}
			if (l2) {
				l2 = l2->next;
			}
		}
		if (carry > 0) {
			tail->next = new ListNode(carry);
		}
		return head;
	}

	int maxDepth(TreeNode * root) {
		if (!root) {
			return 0;
		}
		int maxdepth = dynamicDepth(root, 0);
		return maxdepth;
	}

	int dynamicDepth(TreeNode * node, int depth_now) {
		if (node) {
			depth_now = max(dynamicDepth(node->left, depth_now), dynamicDepth(node->right, depth_now));
			depth_now++;
			return depth_now;
		} else {
			return 0;
		}
	}

	void moveZeroes(vector<int>& nums) {
		int length = nums.size(), left = 0, right = 0;
		while(right < length) {
			if (nums[right]) {
				swap(nums[right], nums[left]);
				left++;
			}
			right++;
		}
	}

	bool isValid(string s) {
		int n = s.size();
		if (n % 2 == 1) return false;
		unordered_map<char, char> dic = {
			{')', '('},
			{']', '['},
			{'}', '{'}
		};
		stack<char> validator;
		for (char x: s) {
			if (dic.count(x)) {
				if (validator.empty() || validator.top() != dic[x]) return false;
				validator.pop();
			} else {
				validator.push(x);
			}
		}
		return validator.empty();
	}

	ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
		ListNode * preHead = new ListNode(-1);
		ListNode * anchor = preHead;
		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val >= l2->val) {
				anchor->next = l2;
				l2 = l2->next;
			} else {
				anchor->next = l1;
				l1 = l1->next;
			}
			anchor = anchor->next;
		}	
		anchor->next = (l1 == nullptr) ? l2 : l1;
		return preHead->next;
	}

}; //Solution