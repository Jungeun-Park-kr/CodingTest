#include <cstdio>
#include<iostream>
#include <unordered_map>

using namespace std;

struct BOX {
    int id;
    int weight;
    int belt;
    BOX* prev;
    BOX* next;

    BOX() {
        id = -1, weight = -1, belt = -1;
        prev = NULL, next = NULL;
    }
};

struct BELT {
    bool is_broken;
    BOX* head;
    BOX* tail;

    BELT() {
        is_broken = 0;
        head = new BOX();
        tail = new BOX();
        head->next = tail, tail->prev = head;
        head->prev = NULL, tail->next = NULL;
    }
};

int q, n, m; // 명령 수, 박스 수, 벨트 수
BOX box[100001];
BELT belt[11];
unordered_map<int, BOX*> box_map;

bool is_belt_empty(int belt_num) {
    //printf("is belt empty %d ? : %d , or broken %d ?\n", belt_num, belt[belt_num].head->next == belt[belt_num].tail, belt[belt_num].is_broken);
    return (belt[belt_num].head->next == belt[belt_num].tail);
}

void push_back(int belt_num, BOX* item) {
    if(belt[belt_num].is_broken) {
        return;
    }
    //printf("belt_num:%d, item->id:%d, item->weight: %d\n", belt_num, item->id, item->weight);
    box_map[item->id] = item;
    BOX* next = belt[belt_num].tail;
    BOX* prev = belt[belt_num].tail->prev;

    next->prev = item;
    item->next = next;
    prev->next = item;
    item->prev = prev;
}

void pop_front(int belt_num) {
    if(is_belt_empty(belt_num)) return;

    BOX* item = belt[belt_num].head->next; // 뽑아낼 victim
    box_map.erase(item->id); 

    BOX* prev = belt[belt_num].head;
    BOX* next = belt[belt_num].head->next->next; // 새로운 첫번째 item이 될 victim

    prev->next = next;
    next->prev = prev;
    item->next = NULL;
    item->prev = NULL;
}

/*
 1. 공장 설립
  - m개의 벨트에 균등하게 박스를 올려줌
*/
void q_100() {
    scanf("%d %d", &n, &m);
    int w[100001], id[100001];
    for(int i=0; i<n; i++) {
        scanf("%d", &id[i]);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &w[i]);
    }

    int idx = 0;
    for(int i=0; i<m; ++i) {
        for(int j=0; j< n/m; ++j) {
            box[idx].id = id[idx];
            box[idx].weight = w[idx];
            box[idx].belt = i;
            push_back(i, &box[idx]);
            ++idx;
        }
    }
}


int q_200() {
    int w_max, ret = 0;
    scanf("%d", &w_max);
    for(int i=0; i<m; ++i) {
        if(is_belt_empty(i)|| belt[i].is_broken ) {
            //printf("벨트 비었거나 고장남! is belt empty:%d, belt[i] broken:%d", is_belt_empty(i), belt[i].is_broken);
            continue;
        }
        //printf("찾아야 함 i:%d, weight:%d", i, belt[i].head->next->weight);
        BOX* item = belt[i].head->next;
        if(item->weight <= w_max) { // 하차
            ret += item->weight;
            pop_front(i);
        } else { // 맨 뒤로 보내기
            pop_front(i);
            push_back(i, item);
        }
    }
    return ret;
}

int q_300() { // 물건 제거
    int r_id;
    scanf("%d", &r_id);
    auto it = box_map.find(r_id);

    if(it == box_map.end()) return -1; // 해당 박스 아이디 없음

    // 꺼내기 -> 뒤에있는 박스 한칸씩 옮기기
    int b_num = it->second->belt; // 벨트 번호
    //printf("r_id : %d 꺼내야 함, 벨트 %d\n", r_id, b_num);
    BOX* item = box_map[r_id];
    BOX* prev = item->prev;
    BOX* next = item->next;
    prev->next = next;
    next->prev = prev;
    item->next = NULL;
    item->prev = NULL;
    box_map.erase(item->id);
    return r_id;
}

int q_400() { // 물건 확인
    int r_id;
    scanf("%d", &r_id);
    auto it = box_map.find(r_id);
    if(it != box_map.end()) { // 뒤에있는 박스 다 앞으로 옮기기
        int b_num = it->second->belt;

        BOX* item = box_map[r_id];
        BOX* begin = belt[b_num].head->next;
        BOX* end = item->prev;
        BOX* item_end = belt[b_num].tail->prev;

        belt[b_num].head->next = item;
        item->prev = belt[b_num].head;
        
        item_end->next = begin;
        begin->prev = item_end;
        
        end->next = belt[b_num].tail;
        belt[b_num].tail->prev = end;

       return b_num+1;
    } else { // 해당 박스 아이디 없음
        return -1;
    }
}

int q_500() { // 벨트 고장
    int b_num;
    scanf("%d", &b_num);
    b_num--;
    if(belt[b_num].is_broken) { // 이미 고장나 있는 경우
        //printf("%d 이미 고장남 끝\n", b_num);
        return -1;
    }
    // 고친 후 벨트 번호 리턴
    int nb_num = (b_num+1)%m; // 옮길 벨트 번호
    //printf("$$  고장난 번호 : %d, 옮길 벨트 번호 : %d\n", b_num, nb_num);
    while(belt[nb_num].is_broken) {
        nb_num = (nb_num+1)%m;
    }

    BOX* obegin = belt[b_num].head->next; // 고장나는 벨트 시작
    BOX* oend = belt[b_num].tail->prev; // 고장나는 벨트 끝

    // 고장 날 벨트에 있는 상자들 벨트 번호 새 번호로 바꿔주기
    BOX* item = obegin;
    while(item != belt[b_num].tail) {
        item->belt = nb_num; // 벨트 번호 변경
        //printf("id : %d 벨트 번호 %d -> %d\n", item->id, b_num, item->belt);
        item = item->next;
    }
    //printf("obegin id : %d, oend id : %d\n", obegin->id, oend->id);

    belt[nb_num].tail->prev->next = obegin;
    obegin->prev = belt[nb_num].tail->prev;

    oend->next = belt[nb_num].tail;
    belt[nb_num].tail->prev = oend;

    // 고장난 벨트 제거 및 초기화
    belt[b_num].is_broken = true;
    belt[b_num].head->next = belt[b_num].tail;
    belt[b_num].tail->prev = belt[b_num].head;
    
    return b_num+1;
}

int main() {
   //freopen("input.txt", "r", stdin);
    int cmd;
    scanf("%d", &q); // 쿼리 수
    for(int tc=0; tc<q; tc++) {
        scanf("%d", &cmd); // 명령어
        switch(cmd) {
            case 100:
                q_100();
            break;
            case 200:
                printf("%d\n", q_200());
            break;
            case 300:
                printf(" ## 300 물건 제거\n");
                printf("%d\n", q_300());
            break;
            case 400:
                printf(" ## 400 물건 확인, 있으면 맨 뒤 까지 맨 앞으로 이동\n");
                printf("%d\n", q_400());
            break;
            case 500:
                printf(" ## 500 벨트 고장, 고장난것 오른쪽 맨 뒤로 다 옮기기\n");
                printf("%d\n", q_500());
            break;
        }

       // 현재 벨트 상태 출력
        for(int i=0; i<m; i++) {
            printf(" === 벨트 %d 번 (고장 : %d)=== \n", i, belt[i].is_broken);
            BOX* item = belt[i].head->next;
            while(item != belt[i].tail) {
                printf("id: %d, weight: %d belt_num:%d\n", item->id, item->weight, item->belt);
                item = item->next;
            }
        }
    }
    return 0;
}