// Function : FUN_400e9e44
// Address  : 0x400e9e44
// Size     : 278 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400e9e44(undefined4 param_1,int param_2,undefined4 param_3,uint *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  undefined4 uVar9;
  char *pcVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  
  iVar4 = _DAT_3ffc51dc;
  uVar9 = 0;
  if ((*param_4 & 0xffffbfff) == 8) {
    if (_DAT_3ffc51dc == 0) {
      uVar12 = func_0x40085c04();
      uVar9 = FUN_401847ec(&DAT_3f40931c);
      uVar1 = (*(code *)&SUB_4000cff8)((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),1000,0);
      pcVar10 = "or %X\r\n";
      uVar11 = 0x68;
    }
    else {
      iVar2 = 0;
      iVar8 = _DAT_3ffc51e0 - 1;
      iVar5 = iVar8 - (iVar8 >> 0x1f);
      while (iVar5 = iVar5 >> 1, iVar2 <= iVar8) {
        puVar7 = *(ushort **)(iVar4 + iVar5 * 4);
        uVar6 = (*puVar7 & 0xff) << 8 | (uint)(*puVar7 >> 8);
        iVar3 = func_0x4008b344(*(undefined4 *)(param_2 + 0x40),puVar7 + 2,uVar6);
        if (iVar3 == 0) {
          iVar4 = FUN_400e9cc4(param_2,(int)puVar7 + uVar6 + 4,
                               CONCAT21(puVar7[1],*(undefined1 *)((int)puVar7 + 3)) & 0xffff);
          if (iVar4 == 0) {
            *param_4 = 0;
            return 0;
          }
          break;
        }
        if (iVar3 < 0) {
          iVar8 = iVar5 + -1;
        }
        else {
          iVar2 = iVar5 + 1;
        }
        iVar5 = (iVar2 + iVar8) - (iVar2 + iVar8 >> 0x1f);
      }
      uVar12 = func_0x40085c04();
      uVar9 = FUN_401847ec(&DAT_3f40931c);
      uVar1 = (*(code *)&SUB_4000cff8)((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),1000,0);
      uVar11 = 0x93;
      pcVar10 = "undle\r\n";
    }
    FUN_4012105c(pcVar10,uVar1,uVar9,uVar11,"gnature");
    uVar9 = 0xffffd000;
  }
  return uVar9;
}

