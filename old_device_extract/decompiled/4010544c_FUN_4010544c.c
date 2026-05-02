// Function : FUN_4010544c
// Address  : 0x4010544c
// Size     : 100 bytes


int FUN_4010544c(int param_1,undefined1 param_2,int param_3,uint param_4,int *param_5,
                undefined4 *param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  param_4 = param_4 & 0xffff;
  *param_5 = param_4 + 4;
  memw();
  iVar1 = (*(code *)&SUB_40094d60)(param_4 + 0x12);
  iVar3 = iVar1;
  if (iVar1 != 0) {
    iVar3 = iVar1 + 0xe;
    *(undefined1 *)(iVar1 + 0xe) = *(undefined1 *)(param_1 + 0x22c);
    *(ushort *)(iVar1 + 0x10) = (ushort)(param_4 << 8) | (ushort)(param_4 >> 8);
    *(undefined1 *)(iVar1 + 0xf) = param_2;
    memw();
    if (param_3 == 0) {
      uVar2 = (*(code *)&SUB_4008b530)(iVar1 + 0x12,0,param_4);
    }
    else {
      memw();
      uVar2 = (*(code *)&SUB_4008b3d0)();
    }
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = uVar2;
    }
  }
  memw();
  return iVar3;
}

