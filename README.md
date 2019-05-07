# determinant (определитель матрицы)
Классический алгоритм вычисления определителя матрицы с помощью миноров и рекурсии.
Как ни странно, все виденные мною реализации этого алгоритма на каждом вызове рекурсии создают новую матрицу и копируют в неё минор.
В то время, как совершенно ничего не мешает получать минор, используя указатели на исходную матрицу. 
Это уменьшает затраты и памяти, и машинного времени.
Правда вычисление определителя через миноры изначально алгоритмически не эффективно, возможно поэтому никто и не заморачивается с его оптимизацией.
Количество операций в этом алгоритме пропорционально факториалу размера матрицы, а это очень быстрорастущая функция, поэтому использовать этот алгоритм для больших матриц принципиально невозможно. 
Из-за этого практическая ценность этого алгоритма весьма невысока, по сути он пригоден только для учебных целей, чтобы на практике разобрться в сути вопроса.
Тем не менее, приведу здесь версию с указателями, без выделения лишней памяти и копирования миноров. 
Может кому и пригодится в поисках просветления.
А для практического вычисления определителей стоит использовать метод Гауса - он не имеет таких жёстких ограничений на размер матрицы.

