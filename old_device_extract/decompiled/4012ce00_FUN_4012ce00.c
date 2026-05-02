// Function : FUN_4012ce00
// Address  : 0x4012ce00
// Size     : 275 bytes


undefined4 FUN_4012ce00(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 4) = 0;
  memw();
  FUN_40185804(param_1,0);
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x204) = 0;
  memw();
  (*(code *)&SUB_4008b530)(param_1 + 0x208,0,0xc);
  (*(code *)&SUB_4008b530)(param_1 + 0x214,0,0xc);
  *(undefined4 *)(param_1 + 0x200) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  memw();
  FUN_40129ca8(param_1);
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined2 *)(param_1 + 0x8c) = 0;
  memw();
  memw();
  FUN_40129a5c(param_1);
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  if (*(char *)(param_1 + 0xe6) != '\0') {
    *(undefined1 *)(param_1 + 0xe6) = 0;
    memw();
  }
  memw();
  (*(code *)&SUB_4008b530)(param_1 + 0xdc,0,8);
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  memw();
  (*(code *)&SUB_4008b530)(*(undefined4 *)(param_1 + 0xb8),0,0x414d);
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x88) = 0;
    memw();
    (*(code *)&SUB_4008b530)(*(undefined4 *)(param_1 + 100),0,0x414d);
  }
  if (*(int *)(param_1 + 0x50) != 0) {
    FUN_40129d74();
    FUN_4013ae44(*(undefined4 *)(param_1 + 0x50));
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  if (*(int *)(param_1 + 0x3c) != 0) {
    memw();
    FUN_4012cacc();
    FUN_4013ae44(*(undefined4 *)(param_1 + 0x3c));
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  *(undefined4 *)(param_1 + 0xf0) = 0;
  if (param_2 == 0) {
    memw();
    FUN_4013ae44(*(undefined4 *)(param_1 + 0x1f8));
    *(undefined4 *)(param_1 + 0x1f8) = 0;
    *(undefined4 *)(param_1 + 0x1fc) = 0;
  }
  memw();
  uVar1 = FUN_4012cb68(param_1);
  return uVar1;
}

