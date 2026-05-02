// Function : FUN_400ed234
// Address  : 0x400ed234
// Size     : 202 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_400ed234(undefined4 *param_1,uint param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  uint auStack_24 [9];
  
  auStack_24[0] = FUN_400ed1b4(param_1,param_2);
  if (((auStack_24[0] != 0) && (param_3 != 0)) && (param_4 != 0)) {
    if (param_4 < auStack_24[0]) {
      uVar7 = func_0x40085c04();
      uVar1 = FUN_401847ec(&DAT_3f409974);
      uVar2 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
      pcVar5 = "%s %s\r\n";
      uVar6 = 0x203;
      param_2 = param_4;
      uVar4 = auStack_24[0];
    }
    else {
      uVar3 = FUN_400f9a2c(*param_1,param_2,param_3,auStack_24);
      if (uVar3 == 0) {
        return auStack_24[0];
      }
      uVar7 = func_0x40085c04();
      uVar2 = (*(code *)&SUB_4000cff8)((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),1000,0);
      uVar1 = FUN_401847ec(&DAT_3f409974);
      uVar4 = _DAT_3ffbdb9c;
      if (0x1100 < (int)uVar3) {
        uVar4 = *(uint *)(&DAT_3ffbdb9c + (uVar3 & 0xffffeeff) * 4);
      }
      uVar6 = 0x208;
      pcVar5 = " < %u\r\n";
    }
    FUN_4012105c(pcVar5,uVar2,uVar1,uVar6,"%s %s\r\n",param_2,uVar4);
    auStack_24[0] = 0;
  }
  return auStack_24[0];
}

