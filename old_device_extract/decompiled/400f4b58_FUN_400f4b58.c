// Function : FUN_400f4b58
// Address  : 0x400f4b58
// Size     : 412 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_400f4b58(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint uVar4;
  char *pcVar5;
  
  if (_DAT_3ffc5554 == (int *)0x0) {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","set_pin",0x3c,"en");
    uVar1 = 0x103;
  }
  else {
    if (param_1 < 8) {
      if (param_2 < 2) {
        if ((param_3 < 3) && (param_4 < 3)) {
          if ((param_5 < 3) && (param_6 < 3)) {
            if (param_2 == 0) {
              puVar3 = (uint *)(*_DAT_3ffc5554 + param_1 * 0xc);
              memw();
              memw();
              *puVar3 = *puVar3 & 0xfff3ffff | (param_3 & 3) << 0x12;
              memw();
              memw();
              *puVar3 = *puVar3 & 0xfffcffff | (param_4 & 3) << 0x10;
              memw();
              memw();
              *puVar3 = *puVar3 & 0xffcfffff | (param_5 & 3) << 0x14;
              memw();
              uVar4 = *puVar3 & 0xff3fffff | (param_6 & 3) << 0x16;
            }
            else {
              puVar3 = (uint *)(*_DAT_3ffc5554 + param_1 * 0xc);
              memw();
              memw();
              *puVar3 = *puVar3 & 0xf3ffffff | (param_3 & 3) << 0x1a;
              memw();
              memw();
              *puVar3 = *puVar3 & 0xfcffffff | (param_4 & 3) << 0x18;
              memw();
              memw();
              *puVar3 = *puVar3 & 0xcfffffff | (param_5 & 3) << 0x1c;
              memw();
              uVar4 = *puVar3 & 0x3fffffff | (param_6 & 3) << 0x1e;
              memw();
            }
            memw();
            *puVar3 = uVar4;
            memw();
            return 0;
          }
          uVar1 = (*(code *)&SUB_40094b80)();
          pcVar5 = "E ERROR";
          uVar2 = 0x40;
          memw();
        }
        else {
          uVar1 = (*(code *)&SUB_40094b80)();
          pcVar5 = "M ERROR";
          uVar2 = 0x3f;
          memw();
        }
      }
      else {
        uVar1 = (*(code *)&SUB_40094b80)();
        pcVar5 = "e error";
        uVar2 = 0x3e;
        memw();
      }
    }
    else {
      uVar1 = (*(code *)&SUB_40094b80)();
      pcVar5 = "r error";
      uVar2 = 0x3d;
    }
    memw();
    FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","set_pin",uVar2,pcVar5);
    uVar1 = 0x102;
  }
  return uVar1;
}

