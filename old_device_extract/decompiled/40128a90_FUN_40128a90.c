// Function : FUN_40128a90
// Address  : 0x40128a90
// Size     : 71 bytes


int FUN_40128a90(undefined4 param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if ((param_3 < param_4) || (uVar1 = FUN_401317d8(param_1), param_3 < uVar1)) {
    iVar4 = -1;
  }
  else {
    iVar3 = 0;
    if (uVar1 < param_4) {
      iVar3 = param_4 - uVar1;
    }
    (*(code *)&SUB_4008b530)(param_2,0,iVar3);
    uVar2 = FUN_401317d8(param_1);
    iVar4 = FUN_40131900(param_1,param_2 + iVar3,uVar2);
    if (iVar4 == 0) {
      iVar4 = uVar1 + iVar3;
    }
  }
  return iVar4;
}

