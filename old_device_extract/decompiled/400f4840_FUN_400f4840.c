// Function : FUN_400f4840
// Address  : 0x400f4840
// Size     : 354 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f4840(uint param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  
  if (_DAT_3ffc5554 == (int *)0x0) {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","_enable",0x93,"en");
    return 0x103;
  }
  if (7 < param_1) {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar7 = "r error";
    uVar2 = 0x94;
    goto LAB_400f488a;
  }
  if (0x40 < param_2) {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar7 = "T ERROR";
    uVar2 = 0x95;
    memw();
    goto LAB_400f488a;
  }
  if (param_2 == 0x10) {
    puVar3 = (uint *)(*_DAT_3ffc5554 + param_1 * 0xc);
    memw();
    uVar4 = *puVar3;
    uVar5 = (param_3 & 1) << 0xd;
    uVar6 = 0xffffdfff;
  }
  else if (param_2 < 0x11) {
    if (param_2 == 4) {
      puVar3 = (uint *)(*_DAT_3ffc5554 + param_1 * 0xc);
      memw();
      uVar4 = *puVar3;
      uVar5 = (param_3 & 1) << 0xf;
      uVar6 = 0xffff7fff;
    }
    else {
      if (param_2 != 8) goto LAB_400f48d5;
      puVar3 = (uint *)(*_DAT_3ffc5554 + param_1 * 0xc);
      memw();
      uVar4 = *puVar3;
      uVar5 = (param_3 & 1) << 0xe;
      uVar6 = 0xffffbfff;
    }
  }
  else {
    if (param_2 != 0x20) {
      if (param_2 == 0x40) {
        puVar3 = (uint *)(*_DAT_3ffc5554 + param_1 * 0xc);
        memw();
        memw();
        *puVar3 = *puVar3 & 0xfffff7ff | (param_3 & 1) << 0xb;
        memw();
        goto LAB_400f4945;
      }
LAB_400f48d5:
      uVar1 = (*(code *)&SUB_40094b80)();
      pcVar7 = "T ERROR";
      uVar2 = 0xa7;
      memw();
LAB_400f488a:
      memw();
      FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","_enable",uVar2,pcVar7);
      return 0x102;
    }
    puVar3 = (uint *)(*_DAT_3ffc5554 + param_1 * 0xc);
    memw();
    uVar4 = *puVar3;
    uVar5 = (param_3 & 1) << 0xc;
    uVar6 = 0xffffefff;
  }
  memw();
  *puVar3 = uVar4 & uVar6 | uVar5;
LAB_400f4945:
  memw();
  return 0;
}

