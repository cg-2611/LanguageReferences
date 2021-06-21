public enum Value {
    VALUE1,
    VALUE2,
    VALUE3,
    VALUE4;

    public int getValue() {
        return ordinal() + 1;
    }
}
// These other examples produce the same result and will work for value types other than int
// public enum Value {
//     VALUE1(1),
//     VALUE2(2),
//     VALUE3(3),
//     VALUE4(4);

//     private final int value;

//     private Value(int value) {
//         this.value = value;
//     }

//     public int getValue() {
//         return value;
//     }
// }

// public enum Value {
//     VALUE1,
//     VALUE2,
//     VALUE3,
//     VALUE4;

//     public int getValue() {
//         switch(this) {
//             case VALUE1:
//                 return 1;
//             case VALUE2:
//                 return 2;
//             case VALUE3:
//                 return 3;
//             case VALUE4:
//                 return 4;
//             default:
//                 return 0; 
//         }
//     }
// }
