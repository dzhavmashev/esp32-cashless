// Function : FUN_401245e4
// Address  : 0x401245e4
// Size     : 172 bytes


void FUN_401245e4(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 8) != 0) {
    *(undefined4 *)(param_2 + 200) = 0;
    *(undefined4 *)(param_2 + 0x44) = 0;
    memw();
    (*(code *)&SUB_4008b530)(param_2 + 0x68,0,0x40);
    *(undefined4 *)(param_2 + 0x18) = 1;
    *(undefined4 *)(param_2 + 0x1c) = 2;
    *(undefined4 *)(param_2 + 0xf4) = 4;
    *(undefined4 *)(param_2 + 0xf8) = 5;
    memw();
    FUN_401241c4(param_1,param_2);
    return;
  }
  iVar1 = *(int *)(param_2 + 0x44);
  if (iVar1 == 0) {
    if (*(int *)(param_2 + 0x20) == 0) {
      return;
    }
LAB_4012462c:
    *(undefined4 *)(param_2 + 200) = 1;
    *(undefined4 *)(param_2 + 0x44) = 2;
    memw();
    FUN_40124248(param_1,param_2);
  }
  else {
    if (iVar1 != 2) {
      if (iVar1 != 1) {
        return;
      }
      if (*(int *)(param_2 + 0xc) == 0) goto LAB_4012462c;
    }
    if (*(int *)(param_2 + 0x10) != 0) {
      uVar2 = *(undefined4 *)(param_2 + 0x18);
      *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_2 + 0x1c);
      *(undefined4 *)(param_2 + 0x1c) = uVar2;
      uVar2 = *(undefined4 *)(param_2 + 0xf8);
      *(undefined4 *)(param_2 + 200) = 1;
      *(undefined4 *)(param_2 + 0x44) = 1;
      *(undefined4 *)(param_2 + 0x10) = 0;
      *(undefined4 *)(param_2 + 0xf8) = *(undefined4 *)(param_2 + 0xf4);
      *(undefined4 *)(param_2 + 0xf4) = uVar2;
      memw();
      FUN_401241c4(param_1,param_2);
      if (*(int *)(param_2 + 0xc) != 0) {
        *(undefined4 *)(param_2 + 0xc) = 0;
        memw();
      }
    }
  }
  return;
}

