// Function : FUN_40134624
// Address  : 0x40134624
// Size     : 56 bytes


int FUN_40134624(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 auStack_24 [9];
  
  iVar1 = FUN_40136090(auStack_24,param_2,param_3 - *param_2);
  if (iVar1 == 0) {
    iVar2 = FUN_401378f0(param_1,auStack_24[0]);
    iVar1 = -0x4e80;
    if (iVar2 == 0) {
      iVar1 = FUN_40136028(param_1,param_1 + 0xac,param_2,param_3 - *param_2);
    }
  }
  return iVar1;
}

