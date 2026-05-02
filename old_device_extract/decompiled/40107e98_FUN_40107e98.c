// Function : FUN_40107e98
// Address  : 0x40107e98
// Size     : 126 bytes


void FUN_40107e98(int param_1,uint *param_2,undefined2 *param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  uint uVar3;
  
  uVar2 = *(undefined2 *)(param_1 + 2);
  if (*(char *)(param_1 + 1) == '\n') {
    uVar3 = *(uint *)(param_1 + 8);
    param_2[1] = *(uint *)(param_1 + 0xc);
    param_2[2] = *(uint *)(param_1 + 0x10);
    param_2[3] = *(uint *)(param_1 + 0x14);
    *(undefined1 *)(param_2 + 4) = 0;
    memw();
    *param_2 = uVar3;
    if (((uVar3 & 0xc0ff) == 0x80fe) || (((uVar3 & 0x8fff) - 0x1ff & 0xfffffeff) == 0)) {
      *(char *)(param_2 + 4) = (char)*(undefined4 *)(param_1 + 0x18);
      memw();
    }
    memw();
    uVar2 = FUN_40185288();
    uVar1 = 6;
    *param_3 = uVar2;
  }
  else {
    *param_2 = *(uint *)(param_1 + 4);
    memw();
    uVar2 = FUN_40185288(uVar2);
    uVar1 = 0;
    *param_3 = uVar2;
    memw();
    memw();
  }
  *(undefined1 *)(param_2 + 5) = uVar1;
  memw();
  memw();
  return;
}

