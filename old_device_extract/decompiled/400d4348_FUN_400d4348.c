// Function : FUN_400d4348
// Address  : 0x400d4348
// Size     : 158 bytes


uint FUN_400d4348(uint *param_1)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  undefined1 auStack_30 [8];
  undefined1 uStack_28;
  
  bVar3 = (byte)param_1[2] & 0x7f;
  if (bVar3 == 6) {
    uVar4 = (uint)(byte)*param_1;
  }
  else if (bVar3 < 7) {
    uVar4 = 0;
    if (3 < bVar3) {
      uStack_28 = 0;
      FUN_400d3f78(*param_1,auStack_30);
      uVar4 = FUN_400d4348(auStack_30);
    }
  }
  else if (bVar3 == 10) {
    uVar4 = *param_1;
    if ((uint)(uVar4 + 0x80000000 < uVar4) + param_1[1] != 0) {
      uVar4 = 0;
    }
  }
  else {
    if (bVar3 == 0xc) {
      uVar2 = param_1[1];
      uVar4 = *param_1;
      iVar1 = (*(code *)&SUB_40063768)(uVar4,uVar2,0,0xc1e00000);
      if ((-1 < iVar1) &&
         (iVar1 = (*(code *)&SUB_40063704)(uVar4,uVar2,0xffc00000,0x41dfffff), iVar1 < 1)) {
        uVar4 = (*(code *)&SUB_40002a78)(uVar4,uVar2);
        return uVar4;
      }
    }
    else if (((bVar3 == 8) && (param_1[1] == 0)) && (-1 < (int)*param_1)) {
      return *param_1;
    }
    uVar4 = 0;
  }
  return uVar4;
}

