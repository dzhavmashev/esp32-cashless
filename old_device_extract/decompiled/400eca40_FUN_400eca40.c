// Function : FUN_400eca40
// Address  : 0x400eca40
// Size     : 214 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_400eca40(undefined4 *param_1,int param_2,undefined2 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  
  if ((*(char *)(param_1 + 1) == '\x01') && (param_2 != 0)) {
    if (*(char *)((int)param_1 + 5) != '\0') {
      return 0;
    }
    uVar1 = FUN_400f9658(*param_1,param_2,param_3);
    if (uVar1 == 0) {
      uVar1 = FUN_400f9738(*param_1);
      if (uVar1 == 0) {
        return 2;
      }
      uVar7 = func_0x40085c04();
      uVar2 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
      uVar3 = FUN_401847ec(&DAT_3f409974);
      uVar4 = _DAT_3ffbdb9c;
      if (0x1100 < (int)uVar1) {
        uVar4 = *(undefined4 *)(&DAT_3ffbdb9c + (uVar1 & 0xffffeeff) * 4);
      }
      uVar6 = 0xad;
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
      uVar6 = 0xa8;
    }
    FUN_4012105c(pcVar5,uVar2,uVar3,uVar6,"",param_2,uVar4);
  }
  return 0;
}

