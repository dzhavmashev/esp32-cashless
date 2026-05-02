// Function : FUN_4016fb8c
// Address  : 0x4016fb8c
// Size     : 56 bytes


int FUN_4016fb8c(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_40 [4];
  undefined4 auStack_30 [12];
  
  iVar3 = *(int *)(param_1 + 0xc) + (param_4 ^ 0xffffffff);
  auStack_30[0] = param_3;
  do {
    iVar3 = FUN_40186e68(iVar3,local_40);
    if (local_40[0] == 0) {
      return 0;
    }
    uVar1 = FUN_4016fb3c(param_1);
    iVar2 = FUN_40186ecc(uVar1,param_2,auStack_30);
  } while (iVar2 == 0);
  return iVar2;
}

