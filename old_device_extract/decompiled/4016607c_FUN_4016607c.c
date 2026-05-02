// Function : FUN_4016607c
// Address  : 0x4016607c
// Size     : 126 bytes


void FUN_4016607c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  
  param_1 = param_1 & 0xff;
  memw();
  FUN_40147fe4(5,0x2000,3,0x3f435ba0,param_1,param_2 & 0xff,param_3 & 0xffff,param_4 & 0xff);
  iVar1 = param_1 * -0x20;
  memw();
  *(uint *)(&DAT_3ff73250 + iVar1) = 0;
  memw();
  *(uint *)(&DAT_3ff7325c + iVar1) = (param_4 & 0x7f) << 0xd | param_3 & 0xfff;
  memw();
  *(undefined4 *)((0x1ffb993 - param_1) * 0x20) = 0;
  memw();
  *(undefined4 *)(&DAT_3ff73264 + iVar1) = 0;
  memw();
  *(uint *)(&DAT_3ff73250 + iVar1) = (param_2 & 0xf) << 0xc | 0xc0000005;
  memw();
  return;
}

