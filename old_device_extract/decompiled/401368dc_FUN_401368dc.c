// Function : FUN_401368dc
// Address  : 0x401368dc
// Size     : 138 bytes


int FUN_401368dc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = FUN_401863d8(param_1);
  if (iVar1 == 2) {
    uVar3 = *(uint *)(param_1 + 0x5c);
    iVar1 = (uVar3 >> 3) + 1;
    iVar2 = FUN_401323a8(param_2,iVar1,param_3,param_4);
    if ((((iVar2 == 0) &&
         (iVar2 = FUN_40131a34(param_2,iVar1 * 8 + (uVar3 ^ 0xffffffff)), iVar2 == 0)) &&
        (iVar2 = FUN_4013173c(param_2,uVar3,1), iVar2 == 0)) &&
       (((iVar2 = FUN_4013173c(param_2,0,0), iVar2 == 0 &&
         (iVar2 = FUN_4013173c(param_2,1,0), iVar2 == 0)) && (uVar3 == 0xfe)))) {
      iVar2 = FUN_4013173c(param_2,2,0);
    }
  }
  else {
    iVar2 = -0x4f80;
    if ((iVar1 == 1) &&
       (iVar2 = FUN_40132570(param_2,1,param_1 + 0x4c,param_3,param_4), iVar2 == -0xe)) {
      iVar2 = -0x4d00;
    }
  }
  return iVar2;
}

