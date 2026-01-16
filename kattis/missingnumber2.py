import sys

def find_anomalies(s):
    possible_results = set()

    for start_len in range(1, 6):
        if start_len > len(s):
            break

        pos = 0
        missing_val = None
        sequence = []
        is_valid = True

        if len(first_chunk) > 1 and first_chunk.startswith('0'):
            continue
        
        try:
            current_num = int(first_chunk)
            sequence.append(current_num)
            pos += start_len

        while pos < len(s):
            expected_num = sequence[-1] + 1
            expected_str = str(expected_num)

            if s.startswith(expected_str, pos):
                sequence.append(expected_num)
                pos += len(expected_str)

            elif missing_val is None:
                num_after_missing = expected_num + 1
                str_after_missing = str(num_after_missing)


                    sequence.append(num_after_missing)
                    pos += len(str_after_missing)

                    is_valid = False
                    break

            else:
                is_valid = False
                break

        if is_valid and sequence:

                possible_results.add(missing_val)

                possible_results.add(sequence[0] - 1)
                possible_results.add(sequence[-1] + 1)

    final_ans = sorted([val for val in possible_results if 1 <= val <= 99999])
    
    print(len(final_ans))
    if final_ans:
        print(*final_ans)

num_cases = int(input())
for _ in range(num_cases):
    s = input()
    find_anomalies(s)