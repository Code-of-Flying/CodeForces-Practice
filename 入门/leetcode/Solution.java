package com.cg.controller;


import java.util.*;

/**
 * @description:
 * 1636. 按照频率将数组升序排序
 * 给你一个整数数组 nums ，请你将数组按照每个值的频率 升序 排序。如果有多个值的频率相同，请你按照数值本身将它们 降序 排序。
 * 请你返回排序后的数组。
 * @author: 全兴涛
 * @date: 2022/9/19 17:56
 * @param: 
 * @return: 
 **/

public class Solution {

     /**
     * @description:
     * @author: 全兴涛
     * @date: 2022/9/19 17:58
     * @param:
     * @return:
     **/
    public int[] frequencySort(int[] nums) {
        Map<Integer,Integer> map =new HashMap();
        for(Integer i: nums){
            map.put(i,map.getOrDefault(i,0) + 1);
        }
        List<Integer> list = new ArrayList<>();
        for (Integer num : nums) {
            list.add(num);
        }
        Collections.sort(list,(Integer a, Integer b)->{
            if (map.get(a) - map.get(b) > 0 || map.get(a) - map.get(b) < 0){
                return map.get(a) - map.get(b) < 0 ? -1 : 1;
            }else{
                return b - a;
            }

        });
        for (int i = 0; i < nums.length; i++) {
            nums[i] = list.get(i);
        }
        return nums;

    }

}
