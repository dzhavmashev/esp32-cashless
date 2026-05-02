// Function : FUN_4017f2fc
// Address  : 0x4017f2fc
// Size     : 124 bytes


uint FUN_4017f2fc(undefined4 param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_2 == 0xffffffff) {
LAB_4017f304:
    uVar1 = 0xffffffff;
  }
  else {
    *(ushort *)(param_3 + 3) = (ushort)param_3[3] & 0xffdf;
    uVar1 = param_2 & 0xff;
    uVar3 = param_3[1];
    if (param_3[0xd] == 0) {
      uVar4 = *param_3;
      if (((param_3[4] == 0) || (uVar4 <= param_3[4])) || (*(byte *)(uVar4 - 1) != uVar1)) {
        param_3[0x10] = uVar3;
        *(char *)((int)param_3 + 0x46) = (char)param_2;
        param_3[0xd] = (uint)(param_3 + 0x11);
        *param_3 = (int)param_3 + 0x46;
        param_3[0xf] = uVar4;
        param_3[0xe] = 3;
        param_3[1] = 1;
        return uVar1;
      }
      *param_3 = uVar4 - 1;
    }
    else {
      if (((int)param_3[0xe] <= (int)uVar3) &&
         (iVar2 = (*(code *)&SUB_4008d2c0)(param_1,param_3), iVar2 != 0)) goto LAB_4017f304;
      uVar3 = *param_3;
      *param_3 = uVar3 - 1;
      *(char *)(uVar3 - 1) = (char)param_2;
      uVar3 = param_3[1];
    }
    param_3[1] = uVar3 + 1;
  }
  return uVar1;
}

