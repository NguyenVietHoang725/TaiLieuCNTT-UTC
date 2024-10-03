/* __ITERATOR__
    1. Khái niêm: Iterator là một đối tượng cho phép duyệt qua các phần tử
của container, giống như cách con trỏ trỏ đến các phần tử trong mảng.
    Với Iterator, ta có thể:
        + Truy cập các phần tử của container.
        + Duyệt qua container theo cách tuần tự, ngẫu nhiên, hay đảo ngược.
        + Thao tác trên các phần tử của container (đọc hoặc ghi).
    
    2. Các loại Iterator
    Iterator trong C++ có thể được chia thành các loại dựa trên khả năng
di chuyển và thao tác.
        2.1. Input Iterator
        - Cho phép đọc dữ liệu từ container.
        - Có thể di chuyển về phía trước qua các phần tử.
        - Không thể quay lui hoặc thay đổi dữ liệu.
        Ví dụ: istream_iterator

        2.2. Output Iterator
        - Cho phép ghi dữ liệu vào container.
        - Có thể di chuyển về phía trước qua các phần tử nhưng chỉ ghi vào
        container, không đọc được.
        Ví dụ: ostream_iterator

        2.3. Forward Iterator
        - Cho phép đọc và ghi dữ liệu.
        - Có thể di chuyển về phía trước qua các phần tử.
        Ví dụ: forward_list::iterator

        2.4. Bidirectional Iterator
        - Cho phép đọc, ghi và di chuyển về phía trước và phía sau qua các 
        phần tử.
        Ví dụ: list::iterator, set::iterator

        2.5. Random Access Iterator
        - Cho phép truy cập ngẫu nhiên các phần tử của container, giống như con trỏ trong mảng.
        - Có thể di chuyển tới bất kỳ vị trí nào trong container bằng cách sử dụng toán tử cộng/trừ.
        Ví dụ: vector::iterator, deque::iterator, array::iterator, string::iterator

    3. Các thao tác cơ bản với Iterator
    
*/

