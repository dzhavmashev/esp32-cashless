// Function : FUN_40128d98
// Address  : 0x40128d98
// Size     : 59 bytes


int FUN_40128d98(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_401317d8(param_1 + 4);
  if ((param_3 != 0) && (iVar2 = FUN_40128a90(param_2,param_3,uVar1,uVar1), iVar2 < 0)) {
    return -1;
  }
  iVar2 = 0;
  if (param_4 != 0) {
    iVar2 = FUN_40128a90(param_2 + 0xc,param_4,uVar1,uVar1);
    iVar2 = iVar2 >> 0x1f;
  }
  return iVar2;
}

