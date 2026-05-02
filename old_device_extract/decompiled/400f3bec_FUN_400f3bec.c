// Function : FUN_400f3bec
// Address  : 0x400f3bec
// Size     : 168 bytes


undefined8 FUN_400f3bec(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  uVar1 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"encyMhz","hz",uVar2,"encyMhz","down_en",0x6e,"d): %s\n");
    uVar2 = 0x102;
  }
  else {
    param_2 = FUN_400f36fc(param_1);
    if (param_2 == 0) {
      (*(code *)&SUB_40092a98)(0x3ffbdc34,0xffffffff);
      puVar3 = *(uint **)(&DAT_3f413ee8 + param_1 * 4);
      if (puVar3 + -0xffc0000 < (uint *)0x13ffd) {
        (*(code *)&SUB_40094c54)("ude/hal/gpio_ll.h",0x55,"own_dis","m error");
      }
      memw();
      memw();
      *puVar3 = *puVar3 | 0x80;
      memw();
      (*(code *)&SUB_40092bec)(0x3ffbdc34);
    }
    else {
      FUN_400f59d4(param_1);
    }
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}

