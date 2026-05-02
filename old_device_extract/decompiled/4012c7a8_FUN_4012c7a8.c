// Function : FUN_4012c7a8
// Address  : 0x4012c7a8
// Size     : 152 bytes


undefined4 FUN_4012c7a8(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  memw();
  FUN_4012b9c8(param_1);
  if ((param_3 - 1U < 0x20) && (param_2 != 0)) {
    memw();
    iVar1 = FUN_4013ae30(1,param_3);
    *(int *)(param_1 + 0xcc) = iVar1;
    uVar2 = 0xffff8100;
    if (iVar1 != 0) {
      *(int *)(param_1 + 0xd0) = param_3;
      memw();
      (*(code *)&SUB_4008b3d0)(iVar1,param_2);
      if (((param_4 == 0) || (param_5 >> 0x10 != 0)) || (0x4000 < param_5)) {
        uVar2 = 0xffff8f00;
      }
      else {
        iVar1 = FUN_4013ae30(1,param_5);
        *(int *)(param_1 + 0xd4) = iVar1;
        if (iVar1 != 0) {
          *(uint *)(param_1 + 0xd8) = param_5;
          memw();
          (*(code *)&SUB_4008b3d0)(iVar1,param_4,param_5);
          return 0;
        }
        uVar2 = 0xffff8100;
      }
      FUN_4012b9c8(param_1);
    }
  }
  else {
    uVar2 = 0xffff8f00;
  }
  return uVar2;
}

