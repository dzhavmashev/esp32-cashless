// Function : FUN_400e08fc
// Address  : 0x400e08fc
// Size     : 165 bytes


uint FUN_400e08fc(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  undefined1 auStack_30 [8];
  undefined1 uStack_28;
  
  uVar1 = 0;
  if (param_1 != (uint *)0x0) {
    bVar5 = (byte)param_1[2] & 0x7f;
    if (bVar5 == 6) {
      uVar1 = (uint)(byte)*param_1;
    }
    else if (bVar5 < 7) {
      if (3 < bVar5) {
        uStack_28 = 0;
        FUN_400d3f78(*param_1,auStack_30);
        uVar1 = FUN_400e08fc(auStack_30);
      }
    }
    else if (bVar5 == 10) {
      uVar3 = *param_1;
      uVar1 = 0;
      if ((uint)(uVar3 + 0x80000000 < uVar3) + param_1[1] == 0) {
        uVar1 = uVar3;
      }
    }
    else if (bVar5 == 0xc) {
      uVar3 = *param_1;
      uVar4 = param_1[1];
      iVar2 = (*(code *)&SUB_40063768)(uVar3,uVar4,0,0xc1e00000);
      uVar1 = 0;
      if (-1 < iVar2) {
        iVar2 = (*(code *)&SUB_40063704)(uVar3,uVar4,0xffc00000,0x41dfffff);
        uVar1 = 0;
        if (iVar2 < 1) {
          uVar1 = (*(code *)&SUB_40002a78)(uVar3,uVar4);
        }
      }
    }
    else if ((bVar5 == 8) && ((param_1[1] != 0 || (uVar1 = *param_1, (int)*param_1 < 0)))) {
      uVar1 = 0;
    }
  }
  return uVar1;
}

