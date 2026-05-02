// Function : FUN_400ed1b4
// Address  : 0x400ed1b4
// Size     : 127 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400ed1b4(undefined4 *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined4 auStack_24 [9];
  
  auStack_24[0] = 0;
  if ((*(char *)(param_1 + 1) == '\x01') && (param_2 != 0)) {
    uVar1 = FUN_400f9a2c(*param_1,param_2,0,auStack_24);
    if (uVar1 == 0) {
      return auStack_24[0];
    }
    uVar5 = func_0x40085c04();
    uVar2 = (*(code *)&SUB_4000cff8)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
    uVar3 = FUN_401847ec(&DAT_3f409974);
    uVar4 = _DAT_3ffbdb9c;
    if (0x1100 < (int)uVar1) {
      uVar4 = *(undefined4 *)(&DAT_3ffbdb9c + (uVar1 & 0xffffeeff) * 4);
    }
    FUN_4012105c("%s %s\r\n",uVar2,uVar3,0x1f7,"etBytes",param_2,uVar4);
  }
  return 0;
}

