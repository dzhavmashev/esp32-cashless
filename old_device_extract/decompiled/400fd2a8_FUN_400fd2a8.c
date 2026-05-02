// Function : FUN_400fd2a8
// Address  : 0x400fd2a8
// Size     : 89 bytes


undefined4 FUN_400fd2a8(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x102;
  if (param_2 < 2) {
    (*(code *)&SUB_40092a98)(0x3ffbdd30,0xffffffff);
    if (*(int *)(param_2 * 0x20 + 0x3ffc572c) == 0) {
      *(undefined4 *)(param_2 * 0x20 + 0x3ffc572c) = param_1;
      memw();
      (*(code *)&SUB_40092bec)(0x3ffbdd30);
      uVar1 = 0;
    }
    else {
      (*(code *)&SUB_40092bec)(0x3ffbdd30,1);
      uVar1 = 0x101;
    }
  }
  return uVar1;
}

