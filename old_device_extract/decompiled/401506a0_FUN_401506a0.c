// Function : FUN_401506a0
// Address  : 0x401506a0
// Size     : 124 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_401506a0(undefined4 param_1,byte param_2,undefined1 param_3,undefined2 param_4,int param_5,
            ushort param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)param_2;
  if (uVar2 < 0x2c) {
    if (param_5 <= (int)(uint)param_6) {
      iVar1 = (*(code *)&SUB_4008b3d0)(uVar2 * 0x34 + _DAT_3ffc7a5c,param_1,0x20);
      *(undefined4 *)(iVar1 + 0x2c) = param_7;
      *(byte *)(iVar1 + 0x20) = param_2;
      *(undefined4 *)(iVar1 + 0x30) = param_8;
      *(undefined1 *)(iVar1 + 0x21) = param_3;
      *(undefined2 *)(iVar1 + 0x22) = param_4;
      *(int *)(iVar1 + 0x24) = param_5;
      *(ushort *)(iVar1 + 0x28) = param_6;
      memw();
      memw();
      return 0;
    }
    FUN_40147fe4(1,1,1," memory",param_5,(uint)param_6);
  }
  else {
    FUN_40147fe4(1,1,1," max %d",uVar2);
  }
  return 0x102;
}

