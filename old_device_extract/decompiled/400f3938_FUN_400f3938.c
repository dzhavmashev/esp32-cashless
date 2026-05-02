// Function : FUN_400f3938
// Address  : 0x400f3938
// Size     : 128 bytes


undefined4 FUN_400f3938(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  uVar1 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"encyMhz","hz",uVar2,"encyMhz","_enable",0xbf,"d): %s\n");
    uVar2 = 0x102;
  }
  else {
    puVar3 = *(uint **)(&DAT_3f413ee8 + param_1 * 4);
    if (puVar3 + -0xffc0000 < (uint *)0x13ffd) {
      (*(code *)&SUB_40094c54)("ude/hal/gpio_ll.h",0x13f,"disable","io_ll.h");
    }
    memw();
    memw();
    *puVar3 = *puVar3 | 0x200;
    uVar2 = 0;
    memw();
  }
  return uVar2;
}

