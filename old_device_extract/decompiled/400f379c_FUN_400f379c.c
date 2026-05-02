// Function : FUN_400f379c
// Address  : 0x400f379c
// Size     : 204 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f379c(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"encyMhz","hz",uVar2,"encyMhz","disable",0xc6,"d): %s\n");
    uVar2 = 0x102;
  }
  else {
    iVar3 = *_DAT_3ffbdc30;
    if (0x1f < (int)param_1) goto LAB_400f3820;
    memw();
    *(int *)(iVar3 + 0x28) = 1 << 0x20 - (0x20 - ((uint)param_1 & 0x1f));
    while (param_1 = (undefined4 *)((int)(param_1 + 0x3ff4453) * 4),
          param_1 + -0xffc0000 < (undefined4 *)0x13ffd) {
      memw();
      iVar3 = (*(code *)&SUB_40094c54)("ude/hal/gpio_ll.h",0x153,"_enable","r error");
LAB_400f3820:
      memw();
      memw();
      memw();
      memw();
      memw();
      memw();
      *(uint *)(iVar3 + 0x34) =
           *(uint *)(iVar3 + 0x34) & 0xffffff00 |
           1 << 0x20 - (0x20 - ((uint)param_1 & 0x1f)) & 0xffU;
      memw();
    }
    memw();
    *param_1 = 0x100;
    uVar2 = 0;
    memw();
  }
  return uVar2;
}

