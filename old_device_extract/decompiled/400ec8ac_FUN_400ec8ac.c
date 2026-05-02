// Function : FUN_400ec8ac
// Address  : 0x400ec8ac
// Size     : 186 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_400ec8ac(undefined4 *param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  
  cVar1 = *(char *)(param_1 + 1);
  if ((cVar1 != '\0') && (*(char *)((int)param_1 + 5) == '\0')) {
    uVar2 = FUN_400f957c(*param_1);
    if (uVar2 == 0) {
      uVar2 = FUN_400f9738(*param_1);
      if (uVar2 == 0) {
        return cVar1;
      }
      uVar8 = func_0x40085c04();
      uVar3 = (*(code *)&SUB_4000cff8)((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),1000,0);
      uVar4 = FUN_401847ec(&DAT_3f409974);
      uVar7 = _DAT_3ffbdb9c;
      if (0x1100 < (int)uVar2) {
        uVar7 = *(undefined4 *)(&DAT_3ffbdb9c + (uVar2 & 0xffffeeff) * 4);
      }
      uVar6 = 0x50;
      pcVar5 = "l: %s\r\n";
    }
    else {
      uVar8 = func_0x40085c04();
      uVar3 = (*(code *)&SUB_4000cff8)((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),1000,0);
      uVar4 = FUN_401847ec(&DAT_3f409974);
      uVar7 = _DAT_3ffbdb9c;
      if (0x1100 < (int)uVar2) {
        uVar7 = *(undefined4 *)(&DAT_3ffbdb9c + (uVar2 & 0xffffeeff) * 4);
      }
      pcVar5 = "d: %s\r\n";
      uVar6 = 0x4b;
    }
    FUN_4012105c(pcVar5,uVar3,uVar4,uVar6,"utUChar",uVar7);
  }
  return '\0';
}

