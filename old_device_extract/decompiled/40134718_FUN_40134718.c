// Function : FUN_40134718
// Address  : 0x40134718
// Size     : 108 bytes


int FUN_40134718(int param_1,int *param_2,undefined4 param_3,uint param_4,undefined4 param_5,
                undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x58) != 0)) {
    iVar3 = param_1 + 0xd0;
    iVar1 = FUN_401344dc(param_1,iVar3,param_1 + 0xac,param_1 + 0x7c,param_5,param_6);
    if (iVar1 != 0) {
      return iVar1;
    }
    uVar2 = FUN_401317d8(iVar3);
    if (uVar2 <= param_4) {
      *param_2 = (uint)((*(uint *)(param_1 + 0x58) & 7) != 0) + (*(uint *)(param_1 + 0x58) >> 3);
      memw();
      iVar1 = FUN_401863d8(param_1);
      if (iVar1 == 2) {
        iVar1 = FUN_40131880(iVar3);
        return iVar1;
      }
      iVar1 = FUN_40131900(iVar3,param_3,*param_2);
      return iVar1;
    }
  }
  return -0x4f80;
}

