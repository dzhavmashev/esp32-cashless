// Function : FUN_400f1c48
// Address  : 0x400f1c48
// Size     : 254 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_400f1c48(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined8 uVar6;
  
  memw();
  uVar1 = (uint)DAT_3ffc54f6;
  if ((DAT_3ffc54f6 == 0) && (memw(), DAT_3ffc54f5 == '\0')) {
    memw();
    uVar5 = _DAT_3ff5a00c >> 9 & 7;
    if ((uVar5 - 2 & 0xfffffffd) == 0) {
      memw();
      DAT_3ffc54f5 = '\x01';
    }
    else {
      iVar2 = FUN_4011eff4();
      if (iVar2 == 0) {
        func_0x400845f4();
        uVar1 = FUN_400f1c3c();
        if (uVar1 == 0) {
          memw();
          DAT_3ffc54f5 = '\x01';
          uVar6 = func_0x40085c04();
          uVar3 = FUN_401847ec("Arduino");
          uVar4 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
          FUN_4012105c("psram.c",uVar4,uVar3,0x54,"heap!\r\n");
        }
        else {
          iVar2 = FUN_4011f0e0();
          if (iVar2 == 0) {
            FUN_4011dd48(0x1000);
            memw();
            DAT_3ffc54f6 = 1;
          }
          else {
            memw();
            DAT_3ffc54f5 = '\x01';
            uVar6 = func_0x40085c04();
            uVar3 = FUN_401847ec("Arduino");
            uVar4 = (*(code *)&SUB_4000cff8)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),1000,0);
            FUN_4012105c("iled!\r\n",uVar4,uVar3,0x59,"heap!\r\n");
            uVar1 = 0;
          }
        }
      }
      else {
        memw();
        DAT_3ffc54f5 = '\x01';
        if (uVar5 != 5) {
          FUN_400f36e4(0x10,0,0);
          FUN_400f36e4(0x11,0,0);
        }
      }
    }
  }
  return uVar1;
}

