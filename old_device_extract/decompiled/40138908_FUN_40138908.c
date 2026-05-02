// Function : FUN_40138908
// Address  : 0x40138908
// Size     : 588 bytes


char * FUN_40138908(uint param_1)

{
  char *pcVar1;
  int iVar2;
  
  if ((int)param_1 < 1) {
    param_1 = -param_1;
  }
  param_1 = param_1 & 0xffff007f;
  if (param_1 == 0x2a) {
    return "ructure";
  }
  if ((int)param_1 < 0x2b) {
    if (param_1 == 0xe) {
      return "allowed";
    }
    if ((int)param_1 < 0xf) {
      if (param_1 == 7) {
        return "tional)";
      }
      if ((int)param_1 < 8) {
        if (param_1 == 3) {
          return "unction";
        }
        if (3 < (int)param_1) {
          if (param_1 == 5) {
            return "le call";
          }
          if (5 < (int)param_1) {
            return "unction";
          }
          return " a file";
        }
        if (param_1 == 1) {
          return "in file";
        }
        iVar2 = param_1 - 2;
        pcVar1 = "n input";
      }
      else {
        if (param_1 == 10) {
          return "rite to";
        }
        if (10 < (int)param_1) {
          if (param_1 == 0xc) {
            return " output";
          }
          if (0xc < (int)param_1) {
            return " failed";
          }
          return "t found";
        }
        if (param_1 == 8) {
          return " string";
        }
        iVar2 = param_1 - 9;
        pcVar1 = "in file";
      }
    }
    else {
      if (param_1 == 0x20) {
        return "ameters";
      }
      if ((int)param_1 < 0x21) {
        if (param_1 == 0x11) {
          return " failed";
        }
        if ((int)param_1 < 0x12) {
          if (param_1 == 0xf) {
            return "unction";
          }
          iVar2 = param_1 - 0x10;
          pcVar1 = "eptable";
        }
        else {
          if (param_1 == 0x13) {
            return " failed";
          }
          if ((int)param_1 < 0x13) {
            return "library";
          }
          iVar2 = param_1 - 0x14;
          pcVar1 = " failed";
        }
      }
      else {
        if (param_1 == 0x24) {
          return " failed";
        }
        if ((int)param_1 < 0x25) {
          if (param_1 == 0x22) {
            return "lformed";
          }
          if (0x22 < (int)param_1) {
            return "ut data";
          }
          return " length";
        }
        if (param_1 == 0x26) {
          return "ut data";
        }
        if ((int)param_1 < 0x26) {
          return "ey size";
        }
        iVar2 = param_1 - 0x27;
        pcVar1 = " length";
      }
    }
  }
  else {
    if (param_1 == 0x3f) {
      return "to poll";
    }
    if ((int)param_1 < 0x40) {
      if (param_1 == 0x36) {
        return " failed";
      }
      if ((int)param_1 < 0x37) {
        if (param_1 == 0x2f) {
          return " failed";
        }
        if ((int)param_1 < 0x30) {
          if (param_1 == 0x2c) {
            return "o small";
          }
          iVar2 = param_1 - 0x2e;
          pcVar1 = " failed";
        }
        else {
          if (param_1 == 0x34) {
            return " failed";
          }
          if (0x34 < (int)param_1) {
            return "latform";
          }
          iVar2 = param_1 - 0x30;
          pcVar1 = "o small";
        }
      }
      else {
        if (param_1 == 0x3a) {
          return "o large";
        }
        if ((int)param_1 < 0x3b) {
          if (param_1 == 0x38) {
            return "too big";
          }
          if (0x38 < (int)param_1) {
            return "lformed";
          }
          return "lformed";
        }
        if (param_1 == 0x3d) {
          return "to poll";
        }
        if (0x3d < (int)param_1) {
          return "failure";
        }
        iVar2 = param_1 - 0x3c;
        pcVar1 = "in file";
      }
    }
    else {
      if (param_1 == 0x6a) {
        return "invalid";
      }
      if ((int)param_1 < 0x6b) {
        if (param_1 == 0x62) {
          return "ructure";
        }
        if ((int)param_1 < 99) {
          if (param_1 == 0x40) {
            return "e added";
          }
          iVar2 = param_1 - 0x60;
          pcVar1 = " failed";
        }
        else {
          if (param_1 == 0x66) {
            return " length";
          }
          if (param_1 == 0x68) {
            return " length";
          }
          iVar2 = param_1 - 100;
          pcVar1 = "d value";
        }
      }
      else {
        if (param_1 == 0x72) {
          return " failed";
        }
        if ((int)param_1 < 0x73) {
          if (param_1 == 0x6e) {
            return "c error";
          }
          if (param_1 == 0x70) {
            return "aligned";
          }
          iVar2 = param_1 - 0x6c;
          pcVar1 = " failed";
        }
        else {
          if (param_1 == 0x74) {
            return " failed";
          }
          if ((int)param_1 < 0x74) {
            return " failed";
          }
          iVar2 = param_1 - 0x75;
          pcVar1 = " failed";
        }
      }
    }
  }
  if (iVar2 != 0) {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}

