// Function : FUN_4018617c
// Address  : 0x4018617c
// Size     : 111 bytes


uint FUN_4018617c(uint *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = 0xfffffff4;
  if ((param_3 != 0) && (uVar1 = 0xfffffff6, -1 < (int)param_3)) {
    if ((param_3 == 1) || (iVar2 = param_2[1], iVar2 == 0)) {
      uVar1 = 0;
      *param_1 = 0;
    }
    else {
      uVar1 = 0;
      iVar4 = iVar2;
      if (param_3 == 2) {
        *param_1 = *(uint *)param_2[2] & 1;
        memw();
      }
      else {
        do {
          iVar4 = iVar4 + -1;
          uVar3 = ((uint *)param_2[2])[iVar4];
          uVar1 = (uVar3 & 0xffff | (uVar3 >> 0x10 | uVar1 << 0x10) % param_3 << 0x10) % param_3;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        if ((*param_2 < 0) && (uVar1 != 0)) {
          uVar1 = param_3 - uVar1;
        }
        *param_1 = uVar1;
        uVar1 = 0;
        memw();
      }
    }
  }
  memw();
  return uVar1;
}

