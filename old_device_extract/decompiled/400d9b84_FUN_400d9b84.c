// Function : FUN_400d9b84
// Address  : 0x400d9b84
// Size     : 266 bytes


bool FUN_400d9b84(undefined4 param_1,char *param_2)

{
  char cVar1;
  int *piVar2;
  float *pfVar3;
  bool bVar4;
  float *pfVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  
  bVar4 = false;
  if (((((byte)param_2[2] < 0x28) && (0.0 < *(float *)(param_2 + 8))) &&
      ((ushort)(*(short *)(param_2 + 0xe) - 1U) < 5000)) &&
     (((ushort)(*(short *)(param_2 + 0x10) - 1U) < 5000 &&
      ((ushort)(*(short *)(param_2 + 0x66) - 1U) < 5000)))) {
    cVar1 = *param_2;
    if (cVar1 == '\x01') {
      if (9 < (byte)(param_2[100] - 1U)) {
        return false;
      }
      uVar8 = (uint)(byte)param_2[100];
      if (uVar8 == 0) {
        return true;
      }
      pcVar7 = param_2;
      while (param_2 + uVar8 * 8 != pcVar7) {
        if (*(float *)(pcVar7 + 0x14) <= 0.0) {
          return false;
        }
        piVar2 = (int *)(pcVar7 + 0x18);
        pcVar7 = pcVar7 + 8;
        if (*piVar2 == 0) {
          return false;
        }
      }
      pfVar5 = (float *)(param_2 + 0x14);
      for (uVar6 = 1; uVar8 != uVar6; uVar6 = uVar6 + 1 & 0xff) {
        pfVar3 = pfVar5 + 2;
        pfVar5 = pfVar5 + 2;
        if (*pfVar3 <= *pfVar5) {
          return false;
        }
      }
    }
    else {
      if (cVar1 == '\x02') {
        if (*(float *)(param_2 + 0x68) <= 0.0) {
          return false;
        }
        return *(float *)(param_2 + 0x68) <= 60.0;
      }
      if (cVar1 == '\x04') {
        if (0x27 < (byte)param_2[0x7b]) {
          return false;
        }
        if (0x27 < (byte)param_2[0x7c]) {
          return false;
        }
        if (0x27 < (byte)param_2[0x7d]) {
          return false;
        }
        if (((param_2[0x7e] & 0xdfU) != 0x40) && (param_2[0x7e] != 0x10)) {
          return false;
        }
      }
      else {
        if (cVar1 != '\x05') {
          return true;
        }
        if (0x27 < (byte)param_2[0x7b]) {
          return false;
        }
        if (0x27 < (byte)param_2[0x7c]) {
          return false;
        }
      }
    }
    bVar4 = true;
  }
  return bVar4;
}

