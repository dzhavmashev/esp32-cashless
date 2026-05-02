// Function : FUN_4011da90
// Address  : 0x4011da90
// Size     : 70 bytes


void FUN_4011da90(uint param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 & 0xff) < 3) {
    iVar1 = (param_1 & 0xff) * 0x20;
    if (param_2 == 0) {
      *(undefined4 *)(iVar1 + 0x3ffc6558) = 0;
      *(undefined4 *)(iVar1 + 0x3ffc655c) = 0;
      *(undefined4 *)(iVar1 + 0x3ffc6560) = 0;
      *(undefined4 *)(iVar1 + 0x3ffc6564) = 0;
      *(undefined1 *)(iVar1 + 0x3ffc6568) = 0;
      *(undefined1 *)(iVar1 + 0x3ffc656c) = 0;
      memw();
      memw();
    }
    else {
      (*(code *)&SUB_4008b3d0)(iVar1 + 0x3ffc6558,param_2,0x18);
    }
    *(undefined4 *)(iVar1 + 0x3ffc6554) = 0;
  }
  memw();
  return;
}

