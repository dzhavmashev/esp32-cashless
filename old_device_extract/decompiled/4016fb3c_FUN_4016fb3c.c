// Function : FUN_4016fb3c
// Address  : 0x4016fb3c
// Size     : 76 bytes


undefined4 FUN_4016fb3c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_30 [12];
  
  uVar2 = (uint)*(byte *)(param_1 + 0x14);
  if (uVar2 != 0xff) {
    uVar1 = uVar2 & 7;
    if (uVar1 == 2) {
      iVar3 = 2;
      goto LAB_4016fb75;
    }
    if (uVar1 < 3) {
      iVar3 = 4;
      if ((*(byte *)(param_1 + 0x14) & 7) == 0) goto LAB_4016fb75;
    }
    else {
      if (uVar1 == 3) {
        iVar3 = 4;
        goto LAB_4016fb75;
      }
      iVar3 = 8;
      if (uVar1 == 4) goto LAB_4016fb75;
    }
    uVar2 = (*(code *)&SUB_40094bc8)();
  }
  iVar3 = 0;
LAB_4016fb75:
  FUN_4016fa60(uVar2,*(undefined4 *)(param_1 + 8),*(int *)(param_1 + 0xc) - param_2 * iVar3,local_30
              );
  return local_30[0];
}

