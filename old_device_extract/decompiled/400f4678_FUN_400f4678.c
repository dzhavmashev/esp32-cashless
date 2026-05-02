// Function : FUN_400f4678
// Address  : 0x400f4678
// Size     : 447 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f4678(uint param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  
  if (_DAT_3ffc5554 == (int *)0x0) {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","_enable",0xaf,"en");
    return 0x103;
  }
  if (param_1 < 8) {
    if (param_2 < 0x41) {
      if ((param_2 == 0x10) && ((((int)param_3 >> 0xf) - param_3 & 0x8000) != 0)) {
        uVar1 = (*(code *)&SUB_40094b80)();
        pcVar5 = "e error";
        uVar2 = 0xb2;
        memw();
      }
      else {
        if ((param_2 != 0x20) || (-1 < (int)param_3)) {
          if (param_2 == 8) {
            iVar3 = *_DAT_3ffc5554 + param_1 * 0xc;
            memw();
            memw();
            memw();
            uVar4 = *(uint *)(iVar3 + 4) & 0xffff0000 | param_3 & 0xffff;
            memw();
            memw();
            memw();
          }
          else {
            if (8 < param_2) {
              if (param_2 == 0x10) {
                iVar3 = *_DAT_3ffc5554 + param_1 * 0xc;
                memw();
                memw();
                memw();
                uVar4 = *(uint *)(iVar3 + 8) & 0xffff | param_3 << 0x10;
                memw();
                memw();
              }
              else {
                if (param_2 != 0x20) {
                  return 0;
                }
                iVar3 = *_DAT_3ffc5554 + param_1 * 0xc;
                memw();
                memw();
                memw();
                uVar4 = *(uint *)(iVar3 + 8) & 0xffff0000 | param_3 & 0xffff;
                memw();
                memw();
                memw();
              }
              memw();
              *(uint *)(iVar3 + 8) = uVar4;
              memw();
              return 0;
            }
            if (param_2 != 4) {
              return 0;
            }
            iVar3 = *_DAT_3ffc5554 + param_1 * 0xc;
            memw();
            memw();
            memw();
            uVar4 = *(uint *)(iVar3 + 4) & 0xffff | param_3 << 0x10;
            memw();
            memw();
          }
          memw();
          *(uint *)(iVar3 + 4) = uVar4;
          memw();
          return 0;
        }
        uVar1 = (*(code *)&SUB_40094b80)();
        pcVar5 = "e error";
        uVar2 = 0xb3;
        memw();
      }
    }
    else {
      uVar1 = (*(code *)&SUB_40094b80)();
      pcVar5 = "T ERROR";
      uVar2 = 0xb1;
      memw();
    }
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar5 = "r error";
    uVar2 = 0xb0;
  }
  memw();
  FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","_enable",uVar2,pcVar5);
  return 0x102;
}

