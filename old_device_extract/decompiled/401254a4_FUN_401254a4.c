// Function : FUN_401254a4
// Address  : 0x401254a4
// Size     : 112 bytes


undefined4 FUN_401254a4(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 4) == 0) || (param_2 == 0)) {
      uVar3 = 0xffffffff;
    }
    else {
      bVar1 = *(byte *)(param_2 + 0x19c);
      if ((bVar1 & 8) == 0) {
        *(byte *)(param_2 + 0x19c) = bVar1 | 8;
        memw();
        *(undefined4 *)(param_2 + 0x18) = 1;
        memw();
        iVar2 = FUN_40125058(param_2);
        if (iVar2 == 1) {
          return 1;
        }
        *(uint *)(param_2 + 0x18) = bVar1 & 8;
        *(undefined4 *)(param_2 + 0x20) = 1;
        memw();
      }
      else {
        (*(code *)&SUB_4008b530)(param_2 + 0x124,0,0x30);
        *(undefined4 *)(param_2 + 0x24) = 1;
      }
      memw();
      uVar3 = FUN_40125058(param_2);
    }
  }
  return uVar3;
}

