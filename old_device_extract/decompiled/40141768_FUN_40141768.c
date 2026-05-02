// Function : FUN_40141768
// Address  : 0x40141768
// Size     : 111 bytes


int FUN_40141768(undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  char cVar1;
  int iVar2;
  byte *pbVar3;
  uint auStack_24 [9];
  
  iVar2 = FUN_40141738(param_1,param_2,auStack_24,param_3);
  if (iVar2 == 0) {
    if ((auStack_24[0] == 0) || ((*(byte *)*param_1 & 0x80) != 0)) {
LAB_4014177d:
      iVar2 = -100;
    }
    else {
      while (auStack_24[0] != 0) {
        cVar1 = *(char *)*param_1;
        if (cVar1 != '\0') {
          if ((4 < auStack_24[0]) || ((auStack_24[0] == 4 && (cVar1 < '\0')))) goto LAB_4014177d;
          break;
        }
        auStack_24[0] = auStack_24[0] - 1;
        *param_1 = (char *)*param_1 + 1;
        memw();
      }
      *param_4 = 0;
      while (auStack_24[0] != 0) {
        pbVar3 = (byte *)*param_1;
        *param_4 = *param_4 << 8 | (uint)*pbVar3;
        *param_1 = pbVar3 + 1;
        memw();
        auStack_24[0] = auStack_24[0] - 1;
      }
    }
  }
  return iVar2;
}

