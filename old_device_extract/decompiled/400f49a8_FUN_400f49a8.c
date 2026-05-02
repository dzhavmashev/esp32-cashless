// Function : FUN_400f49a8
// Address  : 0x400f49a8
// Size     : 426 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f49a8(uint param_1,uint param_2,uint *param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  uint *in_t0;
  char *pcVar5;
  
  if (_DAT_3ffc5554 == 0) {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","unc_sel",0x49,"en");
    return 0x103;
  }
  if (param_1 < 8) {
    if (param_2 < 2) {
      uVar3 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_3);
      if (((uVar3 & 1) != 0) || ((int)param_3 < 0)) {
        uVar3 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_4);
        if ((uVar3 & 1) == 0) {
          if (-1 < param_4) {
            uVar1 = (*(code *)&SUB_40094b80)();
            pcVar5 = "L ERROR";
            uVar2 = 0x4d;
            memw();
            goto LAB_400f49f3;
          }
          if ((int)param_3 < 0) {
            return 0;
          }
        }
        else if ((int)param_3 < 0) goto LAB_400f4aed;
        puVar4 = *(uint **)(&DAT_3f413ee8 + (int)param_3 * 4);
        if ((uint *)0x13ffc < puVar4 + -0xffc0000) goto LAB_400f4aaa;
        while( true ) {
          puVar4 = in_t0;
          (*(code *)&SUB_40094c54)("ude/hal/gpio_ll.h",0x27d,"r_value","t->num)");
          in_t0 = puVar4;
LAB_400f4aaa:
          memw();
          memw();
          *puVar4 = *puVar4 & 0xffff8fff | 0x2000;
          memw();
          FUN_400f4054(param_3,1);
          FUN_400f3fc0(param_3,0);
          (*(code *)&SUB_40009edc)
                    (param_3,*(undefined4 *)(&DAT_3f413f88 + (param_1 * 2 + param_2) * 8),0);
LAB_400f4aed:
          if (param_4 < 0) break;
          puVar4 = *(uint **)(&DAT_3f413ee8 + param_4 * 4);
          param_3 = puVar4 + -0xffc0000;
          if ((uint *)0x13ffc < param_3) {
            memw();
            memw();
            *puVar4 = *puVar4 & 0xffff8fff | 0x2000;
            memw();
            FUN_400f4054(param_4,1);
            FUN_400f3fc0(param_4,0);
            (*(code *)&SUB_40009edc)
                      (param_4,*(undefined4 *)(&DAT_3f413f8c + (param_1 * 2 + param_2) * 8),0);
            return 0;
          }
        }
        return 0;
      }
      uVar1 = (*(code *)&SUB_40094b80)();
      pcVar5 = "L ERROR";
      uVar2 = 0x4c;
      memw();
    }
    else {
      uVar1 = (*(code *)&SUB_40094b80)();
      pcVar5 = "e error";
      uVar2 = 0x4b;
      memw();
    }
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    pcVar5 = "r error";
    uVar2 = 0x4a;
  }
LAB_400f49f3:
  memw();
  FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","unc_sel",uVar2,pcVar5);
  return 0x102;
}

