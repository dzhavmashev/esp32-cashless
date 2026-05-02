// Function : FUN_400f3734
// Address  : 0x400f3734
// Size     : 102 bytes


undefined4 FUN_400f3734(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  uVar1 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"encyMhz","hz",uVar2,"encyMhz","_enable",0xb8,"d): %s\n");
    uVar2 = 0x102;
  }
  else {
    puVar3 = (uint *)(*(byte *)(param_1 + 0x3ffc098d) + 0x3ff49000);
    memw();
    uVar2 = 0;
    memw();
    *puVar3 = *puVar3 & 0xfffffdff;
    memw();
  }
  return uVar2;
}

