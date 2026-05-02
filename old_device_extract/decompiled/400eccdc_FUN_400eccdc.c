// Function : FUN_400eccdc
// Address  : 0x400eccdc
// Size     : 228 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400eccdc(undefined4 *param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  
  if (((*(char *)(param_1 + 1) != '\0') && (param_2 != 0)) && (param_3 != 0)) {
    if (*(char *)((int)param_1 + 5) != '\0') {
      return 0;
    }
    uVar1 = FUN_400f9774(*param_1,param_2,param_3);
    if (uVar1 == 0) {
      uVar1 = FUN_400f9738(*param_1);
      if (uVar1 == 0) {
        uVar4 = func_0x4008c024(param_3);
        return uVar4;
      }
      uVar7 = func_0x40085c04();
      uVar2 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
      uVar3 = FUN_401847ec(&DAT_3f409974);
      uVar4 = _DAT_3ffbdb9c;
      if (0x1100 < (int)uVar1) {
        uVar4 = *(undefined4 *)(&DAT_3ffbdb9c + (uVar1 & 0xffffeeff) * 4);
      }
      uVar6 = 0x116;
      pcVar5 = "%s %s\r\n";
    }
    else {
      uVar7 = func_0x40085c04();
      uVar2 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
      uVar3 = FUN_401847ec(&DAT_3f409974);
      uVar4 = _DAT_3ffbdb9c;
      if (0x1100 < (int)uVar1) {
        uVar4 = *(undefined4 *)(&DAT_3ffbdb9c + (uVar1 & 0xffffeeff) * 4);
      }
      pcVar5 = "%s %s\r\n";
      uVar6 = 0x111;
    }
    FUN_4012105c(pcVar5,uVar2,uVar3,uVar6,"utBytes",param_2,uVar4);
  }
  return 0;
}

