// Function : FUN_400f3b60
// Address  : 0x400f3b60
// Size     : 137 bytes


undefined8 FUN_400f3b60(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  uVar1 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"encyMhz","hz",uVar2,"encyMhz","down_en",0x5b,"d): %s\n");
    uVar2 = 0x102;
  }
  else {
    param_2 = FUN_400f36fc(param_1);
    if (param_2 == 0) {
      (*(code *)&SUB_40092a98)(0x3ffbdc34,0xffffffff);
      puVar3 = (uint *)(*(byte *)(param_1 + 0x3ffc098d) + 0x3ff49000);
      memw();
      memw();
      *puVar3 = *puVar3 & 0xfffffeff;
      memw();
      (*(code *)&SUB_40092bec)(0x3ffbdc34);
    }
    else {
      FUN_400f5934(param_1);
    }
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}

