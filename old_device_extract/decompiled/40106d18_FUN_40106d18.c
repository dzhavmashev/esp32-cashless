// Function : FUN_40106d18
// Address  : 0x40106d18
// Size     : 115 bytes


int FUN_40106d18(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_4015a428();
  if (iVar1 == 0) {
    iVar1 = FUN_401471ac(0,0);
    if (iVar1 == 0) {
      FUN_401471ac(1,0);
    }
    FUN_40123b40();
    iVar1 = FUN_40146710();
    if (iVar1 == 0) {
      FUN_40123344();
      FUN_40100414();
      FUN_401233d8();
      DAT_3ffc589c = 0;
      memw();
      memw();
    }
    else {
      uVar2 = (*(code *)&SUB_40094b80)();
      FUN_4012113c(1,"k fail\n","t stop\n",uVar2,"k fail\n",iVar1);
    }
  }
  else {
    uVar2 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"k fail\n","fi_init",uVar2,"k fail\n");
    iVar1 = 0x3003;
  }
  return iVar1;
}

