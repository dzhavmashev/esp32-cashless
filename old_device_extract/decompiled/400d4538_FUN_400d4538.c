// Function : FUN_400d4538
// Address  : 0x400d4538
// Size     : 169 bytes


undefined4 FUN_400d4538(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  uint uStack_24;
  
  *param_1 = 0;
  iVar5 = *param_2;
  param_1[1] = 0;
  while( true ) {
    if (iVar5 == 0) {
      return 1;
    }
    iVar4 = *(int *)(iVar5 + 0xc);
    if (iVar4 == 0) {
      iVar3 = FUN_40183ab0(param_1,param_3);
      if (iVar3 == 0) {
        return 0;
      }
    }
    else {
      uVar2 = func_0x4008c024(iVar4);
      cVar1 = *(char *)(iVar5 + 8);
      iVar3 = FUN_40183ab0(param_1,param_3);
      if (iVar3 == 0) {
        return 0;
      }
      if (cVar1 < '\0') {
        uStack_24 = uStack_24 & 0xffffff00;
        iVar4 = FUN_40183bf4(param_3,iVar4,uVar2,uStack_24);
        if (iVar4 == 0) {
          FUN_400d3e98(param_1,iVar3);
          return 0;
        }
        bVar6 = *(byte *)(iVar3 + 8) | 0x80;
      }
      else {
        bVar6 = *(byte *)(iVar3 + 8) & 0x7f;
      }
      *(byte *)(iVar3 + 8) = bVar6;
      *(int *)(iVar3 + 0xc) = iVar4;
    }
    iVar4 = FUN_400d43ec(iVar3,iVar5,param_3);
    if (iVar4 == 0) break;
    iVar5 = (*(code *)&LAB_40183a9a_2)(iVar5);
  }
  return 0;
}

