// Function : FUN_40155820
// Address  : 0x40155820
// Size     : 369 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_40155820(int param_1,undefined1 param_2,uint param_3,undefined1 param_4)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  
  param_3 = param_3 & 0xff;
  uVar4 = 0;
  if ((param_1 != 0) && (uVar4 = 0, (*(byte *)(_DAT_3ffbfd50 + 0x46) & 1) != 0)) {
    if (param_3 < 0x20) {
      bVar1 = false;
      bVar2 = 0;
      uVar3 = 0;
      memw();
      for (; uVar4 < *(byte *)(_DAT_3ffbfd50 + 0x110); uVar4 = uVar4 + 1 & 0xff) {
        iVar8 = _DAT_3ffbfd50 + uVar4 * 0x24;
        pbVar7 = (byte *)(iVar8 + 0xc5);
        bVar5 = *pbVar7 + 1;
        iVar6 = _DAT_3ffbfd50 + uVar4 * 0x24;
        *pbVar7 = bVar5;
        memw();
        memw();
        iVar6 = (*(code *)&SUB_4008c080)(param_1,iVar6 + 0xa4,0x20);
        if (iVar6 == 0) {
          *pbVar7 = 0;
          memw();
          *(undefined1 *)(iVar8 + 0xc6) = param_2;
          *(undefined1 *)(iVar8 + 199) = param_4;
          memw();
          memw();
          FUN_40147fe4(1,8,5,0x3f435e83,param_1,param_2);
LAB_401558d6:
          bVar1 = true;
        }
        else {
          if (bVar1) goto LAB_401558d6;
          if (bVar2 < bVar5) {
            memw();
            uVar3 = uVar4;
            bVar2 = bVar5;
          }
        }
      }
      uVar4 = 1;
      if (!bVar1) {
        if (*(byte *)(_DAT_3ffbfd50 + 0x110) < 3) {
          FUN_40147fe4(1,8,5,0x3f435e5b);
          uVar3 = (uint)*(byte *)(_DAT_3ffbfd50 + 0x110);
          *(byte *)(_DAT_3ffbfd50 + 0x110) = *(byte *)(_DAT_3ffbfd50 + 0x110) + 1;
          memw();
        }
        memw();
        (*(code *)&SUB_4008b3d0)(_DAT_3ffbfd50 + uVar3 * 0x24 + 0xa4,param_1,param_3);
        iVar6 = _DAT_3ffbfd50 + uVar3 * 0x24;
        *(undefined1 *)(iVar6 + param_3 + 0xa5) = 0;
        *(undefined1 *)(iVar6 + 0xc6) = param_2;
        memw();
        *(undefined1 *)(iVar6 + 0xc5) = 0;
        memw();
        *(undefined1 *)(iVar6 + 199) = param_4;
        memw();
        memw();
        FUN_40147fe4(1,8,5,0x3f435e36,param_1,param_2);
        uVar4 = 1;
      }
    }
    else {
      memw();
      FUN_40147fe4(1,8,5,0x3f435eab,param_3,param_1,param_2);
      uVar4 = 0;
    }
  }
  return uVar4;
}

