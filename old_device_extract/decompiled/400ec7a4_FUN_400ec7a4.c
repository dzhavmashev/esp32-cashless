// Function : FUN_400ec7a4
// Address  : 0x400ec7a4
// Size     : 222 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_400ec7a4(int param_1,undefined4 param_2,byte param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  
  if (*(char *)(param_1 + 4) != '\0') {
    return 0;
  }
  *(byte *)(param_1 + 5) = param_3;
  if (param_4 == 0) {
    uVar1 = FUN_400f9524(param_2,param_3 ^ 1,param_1);
  }
  else {
    uVar1 = FUN_400f943c(param_4);
    if (uVar1 != 0) {
      uVar7 = func_0x40085c04();
      uVar2 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
      uVar3 = FUN_401847ec(&DAT_3f409974);
      uVar6 = _DAT_3ffbdb9c;
      if (0x1100 < (int)uVar1) {
        uVar6 = *(undefined4 *)(&DAT_3ffbdb9c + (uVar1 & 0xffffeeff) * 4);
      }
      pcVar4 = "ces.cpp";
      uVar5 = 0x2a;
      goto LAB_400ec7fe;
    }
    uVar1 = FUN_400f948c(param_4,param_2,param_3 ^ 1,param_1);
  }
  if (uVar1 == 0) {
    *(undefined1 *)(param_1 + 4) = 1;
    return 1;
  }
  uVar7 = func_0x40085c04();
  uVar2 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
  uVar3 = FUN_401847ec(&DAT_3f409974);
  uVar6 = _DAT_3ffbdb9c;
  if (0x1100 < (int)uVar1) {
    uVar6 = *(undefined4 *)(&DAT_3ffbdb9c + (uVar1 & 0xffffeeff) * 4);
  }
  uVar5 = 0x32;
  pcVar4 = "d: %s\r\n";
LAB_400ec7fe:
  FUN_4012105c(pcVar4,uVar2,uVar3,uVar5,"r",uVar6);
  return 0;
}

